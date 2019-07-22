module StringHashtbl = Hashtbl

(* lose lose algorithm : http://www.cse.yorku.ca/~oz/hash.html *)
let hashi str =
    let hash = ref 0 in
    String.iter (function x -> hash := !hash + int_of_char x ) str;
    !hash

let () =
    let ht = StringHashtbl.create 5 in
    let values = [ "Hello"; "world"; "42"; "Ocaml"; "H" ] in
    let pairs = List.map (fun s -> (s, hashi s)) values in
    List.iter (fun (k,v) -> StringHashtbl.add ht k v) pairs;
    StringHashtbl.iter (fun k v -> Printf.printf "k = \"%s\", v = %d\n" k v) ht