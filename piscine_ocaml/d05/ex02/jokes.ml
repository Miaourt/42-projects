let jokes = [|  "Un chien et un homme son sur un bateau. Le chien pète, l'homme tombe à l'eau et se noie.\nQuelle est la race du chien ?\n\nUn pékinois.";
				"Un jour Dieu dit à Casto de ramer.\nEt depuis, castorama...";
				"Qu'est-ce qu'une manifestation d'aveugles ?\nUn festival de Cannes";
				"2 hommes discutent :\n- On a beaucoup écrit sur moi.\n- Ah, vous êtes connu ?\n- Non, tatoué";
				"Comment appelle-t-on un nain qui distribue le courrier?\nUn truand... car c'est un nain posteur.";
				"Vous connaissez l'histoire de l'armoire ?\nElle est pas commode...";
				"Pourquoi Napoléon n'a pas acheté une maison ?\nParce qu'il avait déjà un bon appart";
				"Pourquoi un chasseur emmène-t-il son fusil aux toilettes ?\nPour tirer la chasse.";
				"Quel est la date de la fête des fumeurs ?\nLe 1er Juin";
				"Qu'est-ce qu'un steak qui n'en est pas un ?\nUne pastèque";
				"Que dit Frodon devant sa maison?\nC'est là que j'hobbit...";
				"Quelle est la capitale de l'île de Tamalou ?\nGébobola !"|]
let () =
	print_endline jokes.(Random.self_init(); Random.int ((Array.length jokes) - 1)) ;