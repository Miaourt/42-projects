type 'a tree = Nil | Node of 'a * 'a tree * 'a tree

let draw_square x y size =
    let real_x = x - (size / 2) in
    let real_y = y - (size / 2) in
    Graphics.moveto real_x real_y;
    Graphics.lineto (real_x + size) real_y;
    Graphics.lineto (real_x + size) (real_y + size);
    Graphics.lineto real_x (real_y + size);
    Graphics.lineto real_x real_y

let draw_tree_node tree = 
    Graphics.open_graph " 300x400";
    let draw_cell x y value =
        draw_square x y 50;
        Graphics.moveto (x - 20) (y - 20);
        Graphics.draw_string value
    in
    let rec runner x y tree i = match tree with
        | Node ( value , tree_c , tree_b ) ->
            draw_cell x y (string_of_int value);
            runner (x + 60) (y + 70) tree_c (i + 1) ; Graphics.moveto (x + 25) (y); Graphics.lineto (x + 35) (y + 70);
            runner (x + 60) (y - 70) tree_b (i + 1) ; Graphics.moveto (x + 25) (y); Graphics.lineto (x + 35) (y - 70)
        | Nil -> draw_cell x y "Nil"
    in
    runner 50 200 tree 1;
    print_endline (read_line ())

let tests () =

    let arbre_de_ses_mords = Node (1 , Node (2 , Nil , Node (42 , Nil , Nil)) , Nil) in
    draw_tree_node arbre_de_ses_mords

let () = tests ()