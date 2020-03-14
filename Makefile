

DIR= src bin obj data doc

default: make_dir

make_dir: $(DIR)

$(DIR): 
	mkdir $@

