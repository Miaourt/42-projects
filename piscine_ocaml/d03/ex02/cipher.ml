let ft_rot_n n str =
	let runner char =
		let tiny_a = int_of_char 'a' in
		let big_a = int_of_char 'A' in
		let non_euclidian_mod a b = 
			let tmp = a mod b in 
			if tmp < 0 then tmp + b else tmp 
		in
		if 'a' <= char && char <= 'z' then char_of_int ((non_euclidian_mod (int_of_char char - tiny_a + n) 26) + tiny_a)
		else if 'A' <= char && char <= 'Z' then char_of_int ((non_euclidian_mod (int_of_char char - big_a + n) 26) + big_a)
		else char
	in
	String.map runner str

let rot42 string =
    ft_rot_n 42 string

let caesar n string =
    ft_rot_n n string

let xor key string =
	let runner char =
		char_of_int ((int_of_char char) lxor key)
	in
	String.map runner string

let ft_crypt str fs : string =
    let rec runner str = function
        | [] -> str
        | fn :: b -> runner (fn str) b
    in
	runner str fs

let tests () =

print_endline ("rot42 of \"Banane\" : " ^ (rot42 "Banane"));
print_endline ("caesar 13 of \"Coucou\" : " ^ (caesar 13 "Coucou"));
print_endline ("xor 42 of \"abcdefghijklmnopqrstuvwxyz\" : \"" ^ (xor 42 "abcdefghijklmnopqrstuvwxyz") ^ "\"");
print_endline ("xor 42 of \"KHINOLMBC@AFGDEZ[XY^_\\]RSP\" : \"" ^ (xor 42 "KHINOLMBC@AFGDEZ[XY^_\\]RSP") ^ "\"");
print_endline ("ft_crypt 42 of \"Orang-outan\" : \"" ^ (ft_crypt ("Orang-outan") ([rot42; (caesar 21)])) ^ "\"")

let () = tests ()