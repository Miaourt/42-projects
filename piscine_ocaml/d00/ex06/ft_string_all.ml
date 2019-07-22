let is_digit char =
	if (int_of_char char) > 47 && (int_of_char char) < 58 then
		true
	else
		false

let ft_string_all func str =
	let rec runner func str l =
		if l <= 0 then 
			true
		else if ((func (String.get str l))) then
			runner func str (l - 1)
		else
			false
	in
	runner func str ((String.length str) - 1)

let tests () =
	if ft_string_all is_digit "0123456789" then
		print_string "Success!\n"
	else
		print_string "Failure!\n";
	if ft_string_all is_digit "O12EAS67B9" then
		print_string "Success!\n"
	else
		print_string "Failure!\n";
	if ft_string_all is_digit "44444444" then
		print_string "Success!\n"
	else
		print_string "Failure!\n";
	if ft_string_all is_digit "" then
		print_string "Success!\n"
	else
		print_string "Failure!\n"

let () = tests ()