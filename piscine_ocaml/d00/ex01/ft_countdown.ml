let rec ft_countdown nb =
	if nb > 0 then
		print_int nb
	else
		print_char '0';
	print_char '\n';
	if nb > 0 then
		ft_countdown (nb - 1)

let tests () =
	ft_countdown (5);
	ft_countdown (10);
	ft_countdown (-5);
	ft_countdown (0)

let () = tests ()