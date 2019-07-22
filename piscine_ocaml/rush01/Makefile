NAME = main

SOURCEDIR = srcs/
SOURCE = $(wildcard $(SOURCEDIR)/*.mli) $(wildcard $(SOURCEDIR)/*.ml)
CAMLBUILD = ocamlbuild

LIBS = $(WITHGRAPHICS)
WITHGRAPHICS = -package Unix -package Graphics

all: $(NAME)

$(NAME): opt byt
	ln -fs $(NAME).opt $(NAME)

$(NAME).opt: $(SOURCE)
	$(CAMLBUILD) -I $(SOURCEDIR) $(NAME).native $(LIBS)
	mv $(NAME).native $(NAME).opt

$(NAME).byt: $(SOURCE)
	$(CAMLBUILD) -I $(SOURCEDIR) $(NAME).byte $(LIBS)
	mv $(NAME).byte $(NAME).byt

opt: $(NAME).opt
byt: $(NAME).byt

clean:
	$(CAMLBUILD) -clean
	rm -f $(NAME)

fclean: clean

re:
	$(MAKE) clean
	$(MAKE) all

.PHONY: all clean fclean re
