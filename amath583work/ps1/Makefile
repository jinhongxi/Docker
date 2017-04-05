.PHONY: tests483 tests583

tests483: ;
	rm -rf _testdir
	cp ps1.tgz ./_testdir
	cp test_ps1.py ./_testdir
	cd ./_testdir &&	\
	tar -xzf ps1.tgz && \
	python test_ps1.py False

tests583: ;
	rm -rf _testdir
	mkdir _testdir
	cp ps1.tgz ./_testdir
	cp test_ps1.py ./_testdir
	cd ./_testdir &&	\
	tar -xzf ps1.tgz && \
	python test_ps1.py True
