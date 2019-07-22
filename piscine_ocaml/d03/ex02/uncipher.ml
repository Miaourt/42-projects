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

let unrot42 string =
    ft_rot_n (-42) string

let uncaesar n string =
    ft_rot_n (n * (-1)) string

let ft_uncrypt str fs : string =
    let rec runner str = function
        | [] -> str
        | fn :: b -> runner (fn str) b
    in
	runner str fs
let tests () =

print_endline ("unrot42 of \"Rqdqdu\" : " ^ (unrot42 "Rqdqdu"));
print_endline ("uncaesar 13 of \"Pbhpbh\" : " ^ (uncaesar 13 "Pbhpbh"));
print_endline ("ft_uncrypt 42 of \"Zclyr-zfely\" : \"" ^ (ft_uncrypt ("Zclyr-zfely") ([(uncaesar 21); unrot42])) ^ "\"")

let () = tests ()