<div class="show_content">
	<div class="show_pic">
		<?php
		include_once FUNC_F.'ft_islog.php';
		include_once FUNC_F.'ft_get_pic.php';
		include_once FUNC_F.'ft_already_like.php';
		include_once FUNC_F.'ft_nb_like.php';

		echo '<img class="pic" src='.ft_get_pic($_GET["pic"]).'></img>';
		?>
		<form class="likes" action="<?php echo SITE_ROOT_URL ?>/?pics" method="post">
			<input name="id" type="hidden" value="<?php echo $_GET["pic"] ?>">
			<input name="page" type="hidden" value="?pic=<?php echo $_GET["pic"] ?>">
			<input name="action" type="submit" value="<?php
				if (ft_is_like($_GET["pic"])) {
					echo "🌟";
				} else {
					echo "⭐";
				} ?>"><?php echo ft_nb_like($_GET["pic"]) ?>
			<a href="http://twitter.com/share?text=Woah,%20cette%20image%20est%20géniale%20!" tooltip="Partager sur Twitter">🐦</a>
			<a href="https://www.facebook.com/sharer/sharer.php?u=<?php echo SITE_ROOT_URL."?pic=".$_GET["pic"] ?>" tooltip="Partager sur Facebook">📖</a>
		</form>
	</div>
	<div class="comments">
		<div class="comment_container">
			<?php
			$db = ft_db();
			$query = $db->prepare("SELECT comments.id, comments.id_author, comments.content, users.username FROM comments INNER JOIN users ON users.id = comments.id_author WHERE :id = comments.id_pics ORDER BY comments.id ASC");
			if ($query->execute(array('id' => $_GET["pic"]))) {
				$result = $query->fetchall(PDO::FETCH_ASSOC);
				$db = null;
				if ($result) {
					foreach ($result as $key => $value) { ?>
						<div class="comment">
							<div class="comment_username"><?php echo $value['username']?> :</div>
							<div class="comment_content"><?php echo htmlspecialchars($value['content'])?></div>
						</div>
					<?php }
				} else { ?>
					<div class="comment_content"><i>Aucun commentaire pour le moment !</i></div>
				<?php }
			}
			$username = ft_islog();
			if ($username) { ?>
			<div class="comment_username"><?php echo $username ?> :</div>
			<form action="<?php echo SITE_ROOT_URL ?>/?pics" method="post">
				<input name="id" type="hidden" value="<?php echo $_GET["pic"] ?>">
				<input name="page" type="hidden" value="?pic=<?php echo $_GET["pic"] ?>">
				<div class="comment_content">
					<input class="com_content" name="content" type="text" placeholder="Entrez votre commentaire ici...">
				</div>
				<div class="comment_button">
					<input class="com_submit" name="action" type="submit" value="💬">
				</div>
			</form>
			<?php } ?>
		</div>
	</div>
</div>
