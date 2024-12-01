# 소스 파일
SRCS = main.c do_snapshot.c do_recovery.c open.c close.c put.c get.c
TARG_BASELINE = kvs_baseline
TARG_CUSTOM = kvs_custom

# 컴파일러와 옵션
CC = gcc
OPTS = -Wall -g

# Baseline 버전 컴파일
baseline: $(SRCS)
	$(CC) $(OPTS) -o $(TARG_BASELINE) $(SRCS)

# Custom 버전 컴파일 (USE_CUSTOM 매크로 정의 추가)
custom: $(SRCS)
	$(CC) $(OPTS) -DUSE_CUSTOM -o $(TARG_CUSTOM) $(SRCS)

# 정리
clean:
	rm -f $(TARG_BASELINE) $(TARG_CUSTOM)
