let ft_print_rev str =
    let rec print_rev str l =
        print_char (String.get str l);
        if l > 0 then
            print_rev str (l - 1)
    in
    ignore (print_rev str ((String.length str) - 1 ));
    print_char '\n'

let tests () =
    ft_print_rev "Coucou c'est je !";
    ft_print_rev "Heureux de vous rencontrer.";
    ft_print_rev "Nah, je rigole !";
    ft_print_rev "J'suis un sociopathe fini faites gaffe !"

let () = tests ()