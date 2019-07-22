let my_sleep () = Unix.sleep 1

let () =
    if Array.length Sys.argv <> 2 then exit 1 else ();
    let x = try int_of_string Sys.argv.(1) with Failure _ -> exit 1 in
    for i = 1 to x do
        my_sleep();
    done;