let load () : (int * int * int * int) = try	
        let save_channel = open_in "save.itama" in
        let health = min 100 (abs (try int_of_string (input_line save_channel) with End_of_file | Failure _ -> 100)) in
        let energy = min 100 (abs (try int_of_string (input_line save_channel) with End_of_file | Failure _ -> 100)) in
        let hygiene = min 100 (abs (try int_of_string (input_line save_channel) with End_of_file | Failure _ -> 100)) in
        let happy = min 100 (abs (try int_of_string (input_line save_channel) with End_of_file | Failure _ -> 100)) in
        close_in_noerr save_channel;
        (health, energy, hygiene, happy)
    with Sys_error _ -> (100, 100, 100, 100)

let save (a : int) (b : int) (c : int) (d : int) = 	
	let save_channel = open_out "save.itama" in
    Printf.fprintf save_channel "%d\n%d\n%d\n%d" a b c d;
    close_out_noerr save_channel