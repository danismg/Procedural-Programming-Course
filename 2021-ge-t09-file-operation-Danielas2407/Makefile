compile :
	md5sum -c --quiet ./checks/check.init
	gcc t09_01.c academic.c custom.c repository.c -o t09_01
	gcc t09_02.c academic.c custom.c repository.c -o t09_02
	gcc t09_03.c academic.c custom.c repository.c -o t09_03

test_00 :
	./t09_01

test_01 :
	./t09_01
	md5sum -c --quiet ./checks/check.01
	git checkout ./storage

test_02 :
	./t09_02
	git checkout ./storage

test_03 :
	./t09_02
	md5sum -c --quiet ./checks/check.03
	git checkout ./storage

test_04 :
	./t09_03
	git checkout ./storage

test_05 :
	./t09_03
	md5sum -c --quiet ./checks/check.05
	git checkout ./storage
