#include "kvs.h"
#include <time.h> // 시간 측정을 위한 라이브러리

// #define USE_CUSTOM  // Custom 모드 활성화 (주석 처리 시 Baseline 모드 실행)

int main() {
    kvs_t* kvs = kvs_open();
    if (!kvs) {
        printf("Failed to open kvs\n");
        return -1;
    }

    // Prepare workload
    FILE* workload = fopen("cluster004.trc", "r");
    if (!workload) {
        printf("Workload file not found\n");
        kvs_close(kvs);
        return -1;
    }

    char op[10], key[100], value[256];
    while (fscanf(workload, "%9[^,],%99[^,],%255s\n", op, key, value) != EOF) {
        if (strcmp(op, "set") == 0) {
            put(kvs, key, value);
        }
    }
    fclose(workload);

    // Measure do_snapshot time
    clock_t start_snapshot = clock();
    #ifdef USE_CUSTOM
        do_snapshot(kvs, "kvs.img.custom", 1); // Custom
    #else
        do_snapshot(kvs, "kvs.img", 0); // Baseline
    #endif
    clock_t end_snapshot = clock();
    printf("do_snapshot time: %.6f seconds\n", (double)(end_snapshot - start_snapshot) / CLOCKS_PER_SEC);

    // Measure do_recovery time
    kvs_t* recovered_kvs = kvs_open();
    clock_t start_recovery = clock();
    #ifdef USE_CUSTOM
        do_recovery(recovered_kvs, "kvs.img.custom", 1); // Custom
    #else
        do_recovery(recovered_kvs, "kvs.img", 0); // Baseline
    #endif
    clock_t end_recovery = clock();
    printf("do_recovery time: %.6f seconds\n", (double)(end_recovery - start_recovery) / CLOCKS_PER_SEC);

    // Get specific keys after recovery
    printf("tweet55: %s\n", get(recovered_kvs, "tweet55"));
    printf("tweet13843: %s\n", get(recovered_kvs, "tweet13843"));
    printf("tweet3482: %s\n", get(recovered_kvs, "tweet3482"));

    kvs_close(kvs);
    kvs_close(recovered_kvs);
    return 0;
}
