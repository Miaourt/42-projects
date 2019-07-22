class virtual molecule n (lst : Atom.atom list) =
	object (self)
		method name : string = n
		method formula : string = 
			let rec encode nb acc x = match x with
				| [] -> []
				| [e] -> acc @ [(nb + 1, e)]
				| prev :: (next :: rest as tail) ->
					if prev#symbol = next#symbol then encode (nb + 1) acc tail
					else encode 0 (acc @ [(nb + 1, prev)]) tail
				
			in
			let rec tuple_to_string (x : (int * Atom.atom) list) = match x with
				| [] -> ""
				| [(nb, atom)] -> (atom#symbol ^ string_of_int nb)
				| (nb, atom) :: next -> (atom#symbol  ^ string_of_int nb) ^ (tuple_to_string next)
			in
			tuple_to_string (encode 0 [] (self#lst_sorted))

		method lst_sorted : Atom.atom list = 
			let rec runner (lst_o : Atom.atom list) (lst_c : Atom.atom list) (lst_h : Atom.atom list) (lst_r : Atom.atom list) = match lst_o with
				| [] -> lst_c @ lst_h @ List.sort (fun a b -> compare (a#symbol) (b#symbol)) lst_r
				| h :: t -> if h#atomic_number = 6 then runner t ([h] @ lst_c) lst_h lst_r
							else if h#atomic_number = 1 then runner t lst_c ([h] @ lst_h) lst_r
							else runner t lst_c lst_h ([h] @ lst_r)
			in
			runner lst [] [] []

		method print_atoms = ignore (List.iter (fun x -> print_string x#symbol) self#lst_sorted)

	end
