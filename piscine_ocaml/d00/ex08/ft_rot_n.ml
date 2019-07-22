let ft_rot_n n str =
	let runner char =
		let a = if 'a' <= char && char <= 'z' then
			int_of_char 'a'
		else
			int_of_char 'A'
		in
		if ('a' <= char && char <= 'z') || ('A' <= char && char <= 'Z') then
			char_of_int (((int_of_char char - a + n) mod 26) + a)
		else
			char
	in
	String.map runner str

let tests () =
	print_string (ft_rot_n 1 "abcdefghijklmnopqrstuvwxyz");
	print_char '\n';
	print_string (ft_rot_n 13 "abcdefghijklmnopqrstuvwxyz");
	print_char '\n';
	print_string (ft_rot_n 1 "NBzlk qnbjr !");
	print_char '\n';
	print_string (ft_rot_n 42 "0123456789");
	print_char '\n';
	print_string (ft_rot_n 0 "Damned !");
	print_char '\n'

let () = tests ()