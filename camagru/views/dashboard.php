<div class="dashboard">
	<form id="upform" action="<?php echo SITE_ROOT_URL ?>/?pics" method="post" enctype="multipart/form-data">
		<div class="webcam">
			<div id="uploader">
				<input id="fileup" name="data" type="file" size="30">
				<input id="filesubmit" name="action" type="submit" value="⬆️">
			</div>
			<video id="preview_v"></video>
			<div class="selector">
				<div class="selector_effects">
					<div class="effect">
						<label for="r1" ><img class ="effect_pic" src="assets/filters/1p.png"></label>
						<input type="radio" name="effect" value="1" id="r1" checked>
					</div>
					<?php $i = 1; while ($i++ <= 5) {?>
						<div class="effect">
							<label for="r<?php echo $i ?>" ><img class ="effect_pic" src="assets/filters/<?php echo $i ?>p.png"></label>
							<input type="radio" name="effect" value="<?php echo $i ?>" id="r<?php echo $i ?>">
						</div>
					<?php } ?>
				</div>
			</div>
		</div>
	</form>
	<div class="sidebar">
		<div class="recent_pics">
		<p class="empty_message">Vos images apparaitrons ici</p>
		<?php
			include_once FUNC_F.'ft_islog.php';
			include_once FUNC_F.'ft_get_userid.php';
			include_once FUNC_F.'ft_nb_like.php';
			include_once FUNC_F.'ft_nb_comment.php';

			$username = ft_islog();
			$db = ft_db();
			$query = $db->prepare("SELECT pics.id, pics.img_path FROM pics WHERE :userid = pics.id_author ORDER BY pics.id DESC");
			if ($query->execute(array('userid' => ft_get_userid($username)))) {
				$result = $query->fetchall(PDO::FETCH_ASSOC);
				$db = null;
				foreach ($result as $key => $value) {
					?>
						<div class="mypics">
							<div class="mypics_content">
								<a href="<?php echo SITE_ROOT_URL."/?pic=".$value["id"] ?>">
									<img src="<?php echo SITE_ROOT_URL.'/'.$value["img_path"] ?>"></img>
								</a>
								<div class="mypics_desc">
									<div class="mypics_desc_comment">
										<a href="<?php echo SITE_ROOT_URL."/?pic=".$value["id"] ?>">💬<?php echo ft_nb_comment($value["id"]) ?></a>
									</div>
									<div class="mypics_desc_like">
										⭐<?php echo ft_nb_like($value["id"]) ?>
									</div>
									<div class="mypics_desc_del">
										<form action="<?php echo SITE_ROOT_URL ?>/?pics" method="post">
											<input name="id" type="hidden" value="<?php echo $value["id"] ?>">
											<input name="action" type="submit" value="🗑️">
										</form>
									</div>
								</div>
							</div>
						</div>
					<?php
				};
			}
		?>
		<div>
	</div>
	<script src="assets/camera.js"></script>

</div>
