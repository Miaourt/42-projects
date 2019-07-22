let rec hfs_f n =
    if n < 0 then -1
    else if n = 0 then 1
    else (n - (hfs_m (hfs_f (n - 1))))
and hfs_m n =
    if n < 0 then -1
    else if n = 0 then 0
    else (n - (hfs_f (hfs_m (n - 1))))

let tests () =
	print_endline ("Test with M 0 : " ^ string_of_int (hfs_m 0));
    print_endline ("Test with F 0 : " ^ string_of_int (hfs_f 0));
    print_endline ("Test with M 4 : " ^ string_of_int (hfs_m 4));
    print_endline ("Test with F 4 : " ^ string_of_int (hfs_m 4))

let () = tests ()