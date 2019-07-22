module Watchtower =
	struct
		type hour = int
		let zero = 0
		let add a b = let tmp = (a + b) mod 12 in if tmp <= 0 then tmp + 12 else tmp
		let sub a b = let tmp = (a - b) mod 12 in if tmp <= 0 then tmp + 12 else tmp
	end

let () =
	let heure : Watchtower.hour = 10 in
	print_endline (	"Il est " ^ (string_of_int heure) ^ "h, on ajoute 5h, il est dorénavant " ^ (string_of_int (Watchtower.add heure 5)) ^ "h!");
	let heure : Watchtower.hour = 5 in
	print_endline (	"Il est " ^ (string_of_int heure) ^ "h, on retire 7h, il est dorénavant " ^ (string_of_int (Watchtower.sub heure 7)) ^ "h!");
	let heure : Watchtower.hour = 3 in
	print_endline (	"Il est " ^ (string_of_int heure) ^ "h, on retire 3h, il est dorénavant " ^ (string_of_int (Watchtower.sub heure 3)) ^ "h!")
