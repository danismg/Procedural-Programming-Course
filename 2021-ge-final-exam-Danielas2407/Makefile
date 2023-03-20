compile :
	git checkout ./storage
	md5sum -c --quiet ./checks/check.00
	gcc f01_01.c transaction.c repository.c custom.c -o f01_01
	gcc f01_02.c transaction.c repository.c custom.c -o f01_02
	gcc f01_03.c transaction.c repository.c custom.c -o f01_03
	gcc f01_04.c transaction.c repository.c custom.c -o f01_04
	gcc f01_05.c transaction.c repository.c custom.c -o f01_05

test_01 :
	./f01_01

test_02 :
	./f01_02

test_03 :
	./f01_03

test_04 :
	./f01_04
	md5sum -c --quiet ./checks/check.04

test_05 :
	./f01_05
	md5sum -c --quiet ./checks/check.05
