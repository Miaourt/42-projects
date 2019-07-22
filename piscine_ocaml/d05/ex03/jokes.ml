let () =
	if Array.length Sys.argv <> 2 then exit 1;
	let jokes = ref [||] in
	let joke_channel = open_in (Array.get Sys.argv 1) in
	try
		while true do
			jokes := Array.append (!jokes) [|input_line joke_channel|] 
		done
	with End_of_file -> close_in joke_channel;
	Random.self_init();
	if Array.length !jokes < 1 then exit 1;
	print_endline !jokes.(Random.int ((Array.length !jokes)))