module Card =
    struct
        module Color =
            struct
                type t = Spade | Heart | Diamond | Club

                let all = [Heart ; Spade ; Diamond ; Club]

                let toString t = match t with
                    | Spade -> "S"
                    | Heart -> "H"
                    | Diamond -> "D"
                    | Club -> "C"

                let toStringVerbose t = match t with
                    | Spade -> "Spade"
                    | Heart -> "Heart"
                    | Diamond -> "Diamond"
                    | Club -> "Club"
            end


        module Value =
            struct
                type t = T2 | T3 | T4 | T5 | T6 | T7 | T8 | T9 | T10  | Jack  | Queen | King | As

                let all = [T2 ; T3 ; T4 ; T5 ; T6 ; T7 ; T8 ; T9 ; T10  ; Jack  ; Queen ; King ; As]

                let toInt t = match t with
                    | T2    -> 1
                    | T3    -> 2
                    | T4    -> 3
                    | T5    -> 4
                    | T6    -> 5
                    | T7    -> 6
                    | T8    -> 7
                    | T9    -> 8
                    | T10   -> 9
                    | Jack  -> 10
                    | Queen -> 11
                    | King  -> 12
                    | As    -> 13

                let toString t = match t with
                    | T2    -> "2"
                    | T3    -> "3"
                    | T4    -> "4"
                    | T5    -> "5"
                    | T6    -> "6"
                    | T7    -> "7"
                    | T8    -> "8"
                    | T9    -> "9"
                    | T10   -> "10"
                    | Jack  -> "J"
                    | Queen -> "Q"
                    | King  -> "K"
                    | As    -> "A"

                let toStringVerbose t = match t with
                    | T2    -> "2"
                    | T3    -> "3"
                    | T4    -> "4"
                    | T5    -> "5"
                    | T6    -> "6"
                    | T7    -> "7"
                    | T8    -> "8"
                    | T9    -> "9"
                    | T10   -> "10"
                    | Jack  -> "Jack"
                    | Queen -> "Queen"
                    | King  -> "King"
                    | As    -> "As"

                let next t = match t with
                    | T2    -> T3
                    | T3    -> T4
                    | T4    -> T5
                    | T5    -> T6
                    | T6    -> T7
                    | T7    -> T8
                    | T8    -> T9
                    | T9    -> T10
                    | T10   -> Jack
                    | Jack  -> Queen
                    | Queen -> King
                    | King  -> As
                    | As    -> invalid_arg "Y'A RIEN APRÈS LES AS NUNUCHE!"

                let previous t = match t with
                    | T2    -> invalid_arg "Y'A RIEN AVANT LES 2 NUNUCHE!"
                    | T3    -> T2
                    | T4    -> T3
                    | T5    -> T4
                    | T6    -> T5
                    | T7    -> T6
                    | T8    -> T7
                    | T9    -> T8
                    | T10   -> T9
                    | Jack  -> T10
                    | Queen -> Jack
                    | King  -> Queen
                    | As    -> King
            end

        type t = ( Color.t * Value.t )

        let newCard (color : Color.t) (value : Value.t) = (color, value)

        let allSpades = List.map (function x -> newCard Color.Spade x) (Value.all)
        let allHearts = List.map (function x -> newCard Color.Heart x) (Value.all)
        let allDiamonds = List.map (function x -> newCard Color.Diamond x) (Value.all)
        let allClubs = List.map (function x -> newCard Color.Club x) (Value.all)
        let all = allSpades @ allHearts @ allDiamonds @ allClubs

        let getValue ((c, v):t) = v
        let getColor ((c, v):t) = c

        let toString t = ((Value.toString (getValue t)) ^ (Color.toString (getColor t)))
        let toStringVerbose t = "Card(" ^ ((Value.toStringVerbose (getValue t)) ^ ", " ^ (Color.toStringVerbose (getColor t))) ^ ")"

        let compare a b = compare (Value.toInt (getValue a)) (Value.toInt (getValue b))
        let max a b = 
            if (Value.toInt (getValue a)) > (Value.toInt (getValue b)) then a 
            else if (Value.toInt (getValue a)) < (Value.toInt (getValue b)) then b
            else (newCard Color.Diamond Value.T2)
        let min a b = 
            if (Value.toInt (getValue a)) > (Value.toInt (getValue b)) then b 
            else if (Value.toInt (getValue a)) < (Value.toInt (getValue b)) then a
            else a
        let best (lst : (t list)) =
            List.fold_left (fun acc card -> max acc card) (newCard Color.Spade Value.T2) lst

        let isOf t color = if (getColor t) = color then true else false
        let isSpade t = isOf t Color.Spade
        let isHeart t = isOf t Color.Heart
        let isDiamond t = isOf t Color.Diamond
        let isClub t = isOf t Color.Club
    end

type t = (Card.t list)

let newDeck () =
    let isInList lst c = if (List.find_opt (function x -> x = c) lst) <> None then true else false in
    let randomCard =
            Card.newCard 
            (
                match (Random.self_init (); Random.int 3) with
                    | 0 -> Card.Color.Spade
                    | 1 -> Card.Color.Heart
                    | 2 -> Card.Color.Diamond
                    | 3 -> Card.Color.Club
                    | _ -> invalid_arg "Mauvais random, très mauvais."
            )
            (
                match (Random.self_init (); Random.int 12) with
                    | 0 -> Card.Value.T2
                    | 1 -> Card.Value.T3
                    | 2 -> Card.Value.T4
                    | 3 -> Card.Value.T5
                    | 4 -> Card.Value.T6
                    | 5 -> Card.Value.T7
                    | 6 -> Card.Value.T8
                    | 7 -> Card.Value.T9
                    | 8 -> Card.Value.T10
                    | 9 -> Card.Value.Jack
                    | 10 -> Card.Value.Queen
                    | 11 -> Card.Value.King
                    | 12 -> Card.Value.As
                    | _ -> invalid_arg "Mauvais random, très mauvais."
            )
    in

    let rec newDeckCard lst =
        let candidate = randomCard in
        if isInList lst candidate then newDeckCard lst
        else candidate
    in

    let rec runner (lst : Card.t list) =
        if List.length lst >= 52 then lst
        else runner (lst @ [newDeckCard lst])
    in
    runner []