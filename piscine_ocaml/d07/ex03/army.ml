class ['a] army (member : 'a list) =
    object

        val _member : 'a list = member

        method add (el : 'a) = {< _member = el :: _member >}

        method delete =
            let do_del _member =
                match _member with
                | [] -> []
                | h :: t -> t
            in
            {< _member = do_del _member >}
    end