module Board =
	struct
		type t =	char * char * char * 
					char * char * char * 
					char * char * char

	    let empty = '-', '-', '-', 
				    '-', '-', '-', 
				    '-', '-', '-'
        let char_at t x y =
			let a, b, c,
				d, e, f,
				g, h, i = t in
                if x = 1 then
                    match y with
                    | 1 -> a
                    | 2 -> b
                    | 3 -> c
                    | _ -> '*'
                else if x = 2 then
                    match y with
                    | 1 -> d
                    | 2 -> e
                    | 3 -> f
                    | _ -> '*'
                else if x = 3 then
                    match y with
                    | 1 -> g
                    | 2 -> h
                    | 3 -> i
                    | _ -> '*'
                else
                    '*' (* invalid char *)

        (* Utility function to determine the winner of a board *)
		let isWin_tic (board : t) (x : char ) = match board with
			| ( a, b, c,
				_, _, _,
				_, _, _) when a = x && b = x && c = x -> true
			| ( _, _, _,
				a, b, c,
				_, _, _) when a = x && b = x && c = x -> true
			| ( _, _, _,
				_, _, _,
				a, b, c) when a = x && b = x && c = x -> true
			| ( a, _, _,
				b, _, _,
				c, _, _) when a = x && b = x && c = x -> true
			| ( _, a, _,
				_, b, _,
				_, c, _) when a = x && b = x && c = x -> true
			| ( _, _, a,
				_, _, b,
				_, _, c) when a = x && b = x && c = x -> true
			| ( a, _, _,
				_, b, _,
				_, _, c) when a = x && b = x && c = x -> true
			| ( _, _, a,
				_, b, _,
				c, _, _) when a = x && b = x && c = x -> true
			| ( _, _, _,
				_, _, _,
				_, _, _) -> false
		
		let isWinX (board : t) = isWin_tic board 'X'
		let isWinO (board : t) = isWin_tic board 'O'
		let winner (board : t) = if isWinX board then 'X' else if isWinO board then 'O' else '-'
		let isWin (board : t) = if winner board <> '-' then true else false

		let lineToStringRaw t l =
			let a, b, c,
				d, e, f,
				g, h, i = t
			in
			match l with
			| 1 -> (String.make 1 a) ^ " " ^ (String.make 1 b) ^ " " ^ (String.make 1 c)
			| 2 -> (String.make 1 d) ^ " " ^ (String.make 1 e) ^ " " ^ (String.make 1 f)
			| 3 -> (String.make 1 g) ^ " " ^ (String.make 1 h) ^ " " ^ (String.make 1 i)
			| _ -> failwith "Tu cherches quoi là?"

		let lineToStringWin t l =
			if (winner t) = 'O' then
				match l with
				| 1 -> "/ - \\"
				| 2 -> "|   |"
				| 3 -> "\\ - /"
				| _ -> failwith "Tu cherches quoi là?"
			else 
				match l with
				| 1 -> "\\   /"
				| 2 -> "  X  "
				| 3 -> "/   \\"
				| _ -> failwith "Tu cherches quoi là?"

                (* t: board
                 * l: identifier
                 *)
		let lineToString t l = 
			if (isWin t) then
				lineToStringWin t l
			else
				lineToStringRaw t l  

		let isTic c = if c = 'X' || c = 'O' then true else false

		let isFull t =
			let a, b, c,
				d, e, f,
				g, h, i = t
			in
			if	isTic a && isTic b && isTic c &&
				isTic d && isTic e && isTic f &&
				isTic g && isTic h && isTic i then true
			else false

		let isDraw t = if isFull t = true && isWin t = false then true else false

	end

module BigBoard =
	struct
		type t =	Board.t * Board.t * Board.t *
					Board.t * Board.t * Board.t *
					Board.t * Board.t * Board.t

        let empty =     Board.empty ,Board.empty , Board.empty ,
                        Board.empty ,Board.empty , Board.empty ,
                        Board.empty ,Board.empty , Board.empty 

        let changed_board b x y =
            let a,b,c,
                d,e,f,
                g,h,i = b in
            if (x >= 1 && x <= 3) && (y >= 1 && y <= 3) then a
            else if (x >= 4 && x <= 6) && (y >= 1 && y <= 3) then d
            else if (x >= 7 && x <= 9) && (y >= 1 && y <= 3) then g
            else if (x >= 1 && x <= 3) && (y >= 4 && y <= 6) then b
            else if (x >= 4 && x <= 6) && (y >= 4 && y <= 6) then e
            else if (x >= 7 && x <= 9) && (y >= 4 && y <= 6) then h
            else if (x >= 1 && x <= 3) && (y >= 7 && y <= 9) then c
            else if (x >= 4 && x <= 6) && (y >= 7 && y <= 9) then f
            else if (x >= 7 && x <= 9) && (y >= 7 && y <= 9) then i
            else
                Board.empty

        let char_at t x y =
			let a, b, c,
				d, e, f,
				g, h, i = t in
            if (x >= 1 && x <= 3) && (y >= 1 && y <= 3) then Board.char_at a x y 
            else if (x >= 4 && x <= 6) && (y >= 1 && y <= 3) then Board.char_at d (x - 3) y
            else if (x >= 7 && x <= 9) && (y >= 1 && y <= 3) then Board.char_at g (x - 6) y
            else if (x >= 1 && x <= 3) && (y >= 4 && y <= 6) then Board.char_at b x (y - 3)
            else if (x >= 4 && x <= 6) && (y >= 4 && y <= 6) then Board.char_at e (x - 3) (y - 3)
            else if (x >= 7 && x <= 9) && (y >= 4 && y <= 6) then Board.char_at h (x - 6) (y - 3)
            else if (x >= 1 && x <= 3) && (y >= 7 && y <= 9) then Board.char_at c x (y - 6)
            else if (x >= 4 && x <= 6) && (y >= 7 && y <= 9) then Board.char_at f (x - 3) (y - 6)
            else if (x >= 7 && x <= 9) && (y >= 7 && y <= 9) then Board.char_at i (x - 6) (y - 6)
            else
                '*'

		let isWin_tic (bigBoard : t) (x : char) = match bigBoard with
			| ( a, b, c,
				_, _, _,
				_, _, _) when (Board.winner a) = x && (Board.winner b) = x && (Board.winner c) = x -> true
			| ( _, _, _,
				a, b, c,
				_, _, _) when (Board.winner a) = x && (Board.winner b) = x && (Board.winner c) = x -> true
			| ( _, _, _,
				_, _, _,
				a, b, c) when (Board.winner a) = x && (Board.winner b) = x && (Board.winner c) = x -> true
			| ( a, _, _,
				b, _, _,
				c, _, _) when (Board.winner a) = x && (Board.winner b) = x && (Board.winner c) = x -> true
			| ( _, a, _,
				_, b, _,
				_, c, _) when (Board.winner a) = x && (Board.winner b) = x && (Board.winner c) = x -> true
			| ( _, _, a,
				_, _, b,
				_, _, c) when (Board.winner a) = x && (Board.winner b) = x && (Board.winner c) = x -> true
			| ( a, _, _,
				_, b, _,
				_, _, c) when (Board.winner a) = x && (Board.winner b) = x && (Board.winner c) = x -> true
			| ( _, _, a,
				_, b, _,
				c, _, _) when (Board.winner a) = x && (Board.winner b) = x && (Board.winner c) = x -> true
			| ( _, _, _,
				_, _, _,
				_, _, _) -> false
		
		let isWinX (bigBoard : t) = isWin_tic bigBoard 'X'
		let isWinO (bigBoard : t) = isWin_tic bigBoard 'O'
		let winner (bigBoard : t) = if isWinX bigBoard then 'X' else if isWinO bigBoard then 'O' else '-'
		let isWin (bigBoard : t) = if winner bigBoard <> '-' then true else false

		let toString t =
			let a, b, c,
				d, e, f,
				g, h, i = t
			in
			Board.lineToString a 1 ^ " | " ^ Board.lineToString b 1 ^ " | " ^ Board.lineToString c 1 ^ "\n" ^
			Board.lineToString a 2 ^ " | " ^ Board.lineToString b 2 ^ " | " ^ Board.lineToString c 2 ^ "\n" ^
			Board.lineToString a 3 ^ " | " ^ Board.lineToString b 3 ^ " | " ^ Board.lineToString c 3 ^ "\n" ^
			"---------------------\n" ^
			Board.lineToString d 1 ^ " | " ^ Board.lineToString e 1 ^ " | " ^ Board.lineToString f 1 ^ "\n" ^
			Board.lineToString d 2 ^ " | " ^ Board.lineToString e 2 ^ " | " ^ Board.lineToString f 2 ^ "\n" ^
			Board.lineToString d 3 ^ " | " ^ Board.lineToString e 3 ^ " | " ^ Board.lineToString f 3 ^ "\n" ^
			"---------------------\n" ^
			Board.lineToString g 1 ^ " | " ^ Board.lineToString h 1 ^ " | " ^ Board.lineToString i 1 ^ "\n" ^
			Board.lineToString g 2 ^ " | " ^ Board.lineToString h 2 ^ " | " ^ Board.lineToString i 2 ^ "\n" ^
			Board.lineToString g 3 ^ " | " ^ Board.lineToString h 3 ^ " | " ^ Board.lineToString i 3 ^ "\n"
		
		let isFull t =
			let a, b, c,
				d, e, f,
				g, h, i = t
			in
			if	Board.isWin a && Board.isWin b && Board.isWin c &&
				Board.isWin d && Board.isWin e && Board.isWin f &&
				Board.isWin g && Board.isWin h && Board.isWin i then true
			else false

		let isDraw t = if isFull t = true && isWin t = false then true else false

	end

let other_p p = if p = 'X' then 'O' else 'X'

let rec get_input () =
    let split = String.split_on_char ' ' (read_line()) in
    if List.length split <> 2 then 
        begin print_endline "Incorrect format."; get_input () end
    else 
        let opt_list = List.map int_of_string_opt split in
            let rec unwrap (opt_l: int option list) l =
                if List.length l = 2 then l
                else
                    match List.hd opt_l with
                        | Some x -> unwrap (List.tl opt_l) (l @ [x])
                        | None -> []
        in
        let int_list = unwrap opt_list [] in
        if int_list = [] then
            begin print_endline "Incorrect format."; get_input () end
        else if List.for_all (fun x -> x >= 1 && x <= 9) int_list then int_list
        else 
            begin print_endline "Incorrect format."; get_input () end

let newboard board x y pl =
    let a, b, c,
        d, e, f,
        g, h, i = board in
        if x = 1 && y = 1 then
            pl,b,c,d,e,f,g,h,i
        else if x = 1 && y = 2 then
            a,pl,c,d,e,f,g,h,i
        else if x = 1 && y = 3 then
            a,b,pl,d,e,f,g,h,i
        else if x = 2 && y = 1 then
            a,b,c,pl,e,f,g,h,i
        else if x = 2 && y = 2 then
            a,b,c,d,pl,f,g,h,i
        else if x = 2 && y = 3 then
            a,b,c,d,e,pl,g,h,i
        else if x = 3 && y = 1 then
            a,b,c,d,e,f,pl,h,i
        else if x = 3 && y = 2 then
            a,b,c,d,e,f,g,pl,i
        else if x = 3 && y = 3 then
            a,b,c,d,e,f,g,h,pl
        else
            Board.empty

let newboard_wrap b x y pl =
    let nb = (newboard b x y pl) in
    if Board.isDraw nb then
        begin
        print_endline "It's a draw ! Let's replay this one.";
        Board.empty
        end
    else
        nb

let newbigboard b x y p =
    let a, b, c,
        d, e, f,
        g, h, i = b in
            if (x >= 1 && x <= 3) && (y >= 1 && y <= 3) then 
                (newboard_wrap a x y p),b,c,d,e,f,g,h,i
            else if (x >= 4 && x <= 6) && (y >= 1 && y <= 3) then
                a,b,c,(newboard_wrap d (x - 3) y p),e,f,g,h,i
            else if (x >= 7 && x <= 9) && (y >= 1 && y <= 3) then
                a,b,c,d,e,f,(newboard_wrap g (x - 6) y p),h,i
            else if (x >= 1 && x <= 3) && (y >= 4 && y <= 6) then
                a,(newboard_wrap b x (y - 3) p),c,d,e,f,g,h,i
            else if (x >= 4 && x <= 6) && (y >= 4 && y <= 6) then
                a,b,c,d,(newboard_wrap e (x - 3) (y - 3) p),f,g,h,i
            else if (x >= 7 && x <= 9) && (y >= 4 && y <= 6) then
                a,b,c,d,e,f,g,(newboard_wrap h (x - 6) (y - 3) p),i
            else if (x >= 1 && x <= 3) && (y >= 7 && y <= 9) then
                a,b,(newboard_wrap c x (y - 6) p),d,e,f,g,h,i
            else if (x >= 4 && x <= 6) && (y >= 7 && y <= 9) then
                a,b,c,d,e,(newboard_wrap f (x - 3) (y - 6) p),g,h,i
            else if (x >= 7 && x <= 9) && (y >= 7 && y <= 9) then
                a,b,c,d,e,f,g,h,(newboard_wrap i (x - 6) (y - 6) p)
            else
                BigBoard.empty
let endgame p =
    print_string "Player ";
    print_char p;
    print_endline " won !";
    ()

let rec game b p =
    print_endline (BigBoard.toString b);
    if BigBoard.isWin b then endgame (other_p p)
    else
        begin
    print_string "== ";
    print_char p;
    print_endline " == turn";
    
    let move = (get_input ()) in
    let x = List.nth move 0 in
    let y = List.nth move 1 in
    if BigBoard.char_at b x y <> '-' then
        begin print_endline "Illegal move."; game b p end
    else    
        game (newbigboard b x y p) (other_p p)
        end

let () =
    game BigBoard.empty 'X'
