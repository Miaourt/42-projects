<?php

include_once FUNC_F.'ft_db.php';
include_once FUNC_F.'ft_islog.php';
include_once FUNC_F.'ft_already_like.php';
include_once FUNC_F.'ft_nb_like.php';
include_once FUNC_F.'ft_nb_comment.php';


$username = ft_islog();
$db = ft_db();
$start = 0;
if ((isset($_GET['p']) && !($_GET['p'] < 1) && is_numeric($_GET['p'])) || !isset($_GET['p'])) {
	?><div class="gallery"><?php
	$start = (!isset($_GET['p'])) ? 1 : $_GET['p'];
	$pre = $start - 1;
	$next = $start + 1;
	$start = (!isset($_GET['p'])) ? 0 : $_GET['p'] - 1;
	$query = $db->prepare("SELECT pics.id, pics.id_author, pics.img_path, users.username FROM pics INNER JOIN users ON users.id = pics.id_author ORDER BY pics.id DESC LIMIT ". $start * 6 .", 7");
	if ($query->execute()) {
		$result = $query->fetchall(PDO::FETCH_ASSOC);
		$db = null;
		$tmp = 0;
		foreach ($result as $key => $value) if ($tmp++ < 6) {
			?>
				<div class="pics_holder">
					<div class="pics">
						<div class="pics_content">
							<a href="<?php echo SITE_ROOT_URL."/?pic=".$value["id"] ?>">
								<img src="<?php echo SITE_ROOT_URL.'/'.$value["img_path"] ?>"></img>
							</a>
							<div class="pics_desc">
								<div class="pics_desc_author">
									<a>👤 <?php echo $value["username"] ?></a>
								</div>
								<div class="pics_desc_like">
									<form action="<?php echo SITE_ROOT_URL ?>/?pics" method="post">
										<input name="id" type="hidden" value="<?php echo $value["id"] ?>">
										<input name="page" type="hidden" value="?gallery&p=<?php echo $start + 1 ?>">
										<input name="action" type="submit" value="<?php
											if (ft_is_like($value["id"])) {
												echo "🌟";
											} else {
												echo "⭐";
											} ?>"><?php echo ft_nb_like($value["id"]) ?>
									</form>
								</div>
								<div class="pics_desc_comment">
									<a href="<?php echo SITE_ROOT_URL."/?pic=".$value["id"] ?>">💬<?php echo ft_nb_comment($value["id"]) ?></a>
								</div>
							</div>
						</div>
					</div>
				</div>
			<?php
		};
	}
	?>
</div><div class="gallery_nav"> <?php
	if ($pre > 0) { ?>
		<a href="<?php echo SITE_ROOT_URL."?gallery&p=".$pre ?>">⬅️</a>
	<?php } ?>
	<?php echo $start + 1 ?>
	<?php
		if (count($result) > 6) { ?>
			<a href="<?php echo SITE_ROOT_URL."?gallery&p=".$next ?>">➡️</a>
		<?php } ?>
	</div>
	<?php
}
else {
	?>
	Numéro de page invalide 🤔
	<?php
}

?>
