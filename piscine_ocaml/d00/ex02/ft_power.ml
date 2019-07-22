let rec ft_power nb power =
	if power = 0 then 
		1 
	else
		nb * ft_power nb (power - 1)

let tests () =
	print_int (ft_power 2 2);
	print_char '\n';
	print_int (ft_power 5 6);
	print_char '\n';
	print_int (ft_power 7 10);
	print_char '\n';
	print_int (ft_power 988037 0);
	print_char '\n'

let () = tests ()