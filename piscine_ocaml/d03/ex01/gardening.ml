type 'a tree = Nil | Node of 'a * 'a tree * 'a tree

let rec size tree = match tree with
    | Node ( value , tree_a , tree_b ) -> 
        1 + size (tree_a) + size (tree_b)
    | Nil -> 0

let rec height tree = match tree with
    | Node ( value , tree_a , tree_b ) ->
        let height_a = height tree_a in
        let height_b = height tree_b in
        if height_a > height_b then 1 + height_a else 1 + height_b
    | Nil -> 0
    

let draw_tree_node tree = 
    Graphics.open_graph " 400x400";

    let draw_cell x y value =
        Graphics.draw_rect (x - 25) (y - 25) 50 50;
        Graphics.moveto (x - 20) (y - 20);
        Graphics.draw_string value
    in

    let rec runner x y tree = match tree with
        | Node ( value , tree_a , tree_b ) ->
            draw_cell x y value;
            runner (x + 60) (y + 60) tree_a ; Graphics.moveto (x + 25) (y); Graphics.lineto (x + 35) (y + 70);
            runner (x + 60) (y - 60) tree_b ; Graphics.moveto (x + 25) (y); Graphics.lineto (x + 35) (y - 70)
        | Nil -> draw_cell x y "Nil"
    in
    runner 50 200 tree;
    print_endline (read_line ())

let tests () =

    let arbre_de_ses_mords = Node ("Un" , Node ("Deux" , Nil , Node ("Trois" , Nil , Node ("Quatre" , Nil , Nil))) , Nil) in
    print_endline ("Size : " ^ string_of_int (size arbre_de_ses_mords));
    print_endline ("Height : " ^ string_of_int (height arbre_de_ses_mords));
    draw_tree_node arbre_de_ses_mords

let () = tests ()