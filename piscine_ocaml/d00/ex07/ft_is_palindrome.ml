let ft_is_palindrome str =
	let rec runner str i max =
		if i > (max / 2) then
			true
		else if (String.get str i) = (String.get str (max - (1 + i))) then begin
			runner str (i + 1) max
		end
		else
			false
	in
	runner str 0 ((String.length str))

let tests () =
	if ft_is_palindrome "madam" then
		print_string "Success!\n"
	else
		print_string "Failure!\n";
	if ft_is_palindrome "mom" then
		print_string "Success!\n"
	else
		print_string "Failure!\n";
	if ft_is_palindrome "radar" then
		print_string "Success!\n"
	else
		print_string "Failure!\n";
	if ft_is_palindrome "lol" then
		print_string "Success!\n"
	else
		print_string "Failure!\n";
	if ft_is_palindrome "mdr" then
		print_string "Success!\n"
	else
		print_string "Failure!\n";
	if ft_is_palindrome "wof" then
		print_string "Success!\n"
	else
		print_string "Failure!\n"

let () = tests ()