let ft_print_comb () =
	let rec runner x y z =
		print_string ", ";
		print_int x;
		print_int y;
		print_int z;
		if x = 7 && y = 8 && z = 9 then 
			()
		else if y = 8 && z = 9 then
			runner (x + 1) (x + 2) (x +3)
		else if z = 9 then 
			runner x (y + 1) (y + 2)
		else
			runner x y (z + 1)
	in
	print_int 0;
	print_int 1;
	print_int 2;
	runner 0 1 3;
	print_string "\n"

let tests () =
	ft_print_comb()

let () = tests ()