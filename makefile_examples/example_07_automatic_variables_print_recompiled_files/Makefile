hey: one two
	# Outputs "hey" since this is the targets name
	echo $@

	# Outputs all prerequitsitets, newer than the target
	# this means we can see what was recomplied and what was not
	echo $?
	

	# Outputs all prerequitsitets
	# if we recompile this prerequitsitets will show, but we do not know if it was recomplied
	echo $^

	touch hey

one:
	touch one
two:
	touch two

clean:
	rm one two hey