CC:=gcc
#system_test:system_test.c
#	gcc -o system_test system_test.c
#	-./system_test
#	-rm system_test

system_test:system_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@
fork_test:fork_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@
fork_fd_test:fork_fd_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

erlou:erlou.c
	-$(CC) -o $@ $^

execve_test:execve_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

fork_execve_test:fork_execve_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

waitpid_test:waitpid_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

pstree_test:pstree_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@
unnamed_pipe_test:unnamed_pipe_test.c
	-$(CC) -o $@ $^
	-./$@ testttt2
	-rm ./$@

s01_fifo_write:s01_fifo_write.c
	-$(CC) -o $@ $^
	
s02_fifo_read:s02_fifo_read.c
	-$(CC) -o $@ $^

s03_shm_open:s03_shm_open.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@
s04_mq_test:s04_mq_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@	

s05consumer:s05consumer.c
	-$(CC) -o $@ $^


s05producer:s05producer.c
	-$(CC) -o $@ $^

