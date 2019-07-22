let ft_print_alphabet () =
    print_char 'a';
    print_char 'b';
    print_char 'c';
    print_char 'd';
    print_char 'e';
    print_char 'f';
    print_char 'g';
    print_char 'h';
    print_char 'i';
    print_char 'j';
    print_char 'k';
    print_char 'l';
    print_char 'm';
    print_char 'n';
    print_char 'o';
    print_char 'p';
    print_char 'q';
    print_char 'r';
    print_char 's';
    print_char 't';
    print_char 'u';
    print_char 'v';
    print_char 'w';
    print_char 'x';
    print_char 'y';
    print_char 'z';
	print_char '\n'
    
let tests () =
    ft_print_alphabet();
	print_char '\n';
    ft_print_alphabet();
    ft_print_alphabet()

let () = tests ()