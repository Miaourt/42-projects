module App =
	struct
		type project = string * string * int
		let zero = ("", "", 0)
		let combine (a : project) (x : project) = match (a, x) with ((b, _, c),(y, _, z)) -> 
			let average = abs ((c - z) / 2) in
			(b ^ y, (if average >= 80 then "success" else "failed"), average)
		let fail (x : project) = match x with (a, _, _) -> (a , "failed", 0)
		let success (x : project) = match x with (a, _, _) ->  (a , "succeed", 80)
	end

let () =
	let print_proj ((a,b,c): App.project) =
	print_endline ("( " ^ a ^ ", " ^ b ^ ", " ^ string_of_int c ^ " )")
	in
	print_proj ("Project 1", "succeed", 95);
	print_endline "*******";
	let p1 = ("P1", "succeed", 90) and p2 = ("P2", "succeed", 80) in
	print_proj (App.combine p1 p2);
	print_proj (App.fail p1);
	print_endline "*******";
	let p1 = ("toto", "failed", 20) and p2 = ("tata", "succeed", 80) in
	print_proj (App.combine p1 p2);
	print_proj (App.fail p2);
	print_endline "*******";
	let p1 = ("po", "failed", 20) and p2 = ("pi", "failed", 10) in
	print_proj (App.combine p1 p2);
	print_proj (App.success p1)