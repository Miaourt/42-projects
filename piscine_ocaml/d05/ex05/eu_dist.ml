let eu_dist a b =
	if Array.length a <> Array.length b then invalid_arg "Both arrays need to be the same lenght";
	let result = ref 0. in
	for i = 0 to ((Array.length a) - 1) do
		result := !result +. ( ((Array.get a i) -. (Array.get b i)) ** 2. )
	done;
	sqrt !result

let () =
	let a = [|1.0; 2.0; 3.0|] in
	let b = [|4.0; 3.0; 2.0|] in
	print_endline (string_of_float (eu_dist a b))