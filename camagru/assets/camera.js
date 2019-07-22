(function() {
	var streaming	 	= false,
	video	 					= document.querySelector('#preview_v'),
	width	 					= 480,
	height					= 0;

	navigator.getMedia = ( navigator.getUserMedia || navigator.webkitGetUserMedia || navigator.mozGetUserMedia || navigator.msGetUserMedia);
	navigator.getMedia(
		{
			video: true,
			audio: false
		},
		function(stream) {
			if (navigator.mozGetUserMedia) {
				video.mozSrcObject = stream;
			}
			else
			{
				var vendorURL = window.URL || window.webkitURL;
				video.src = vendorURL.createObjectURL(stream);
			}
			document.getElementById('fileup').style.display = "none";
			document.getElementById('filesubmit').style.display = "none";
			document.getElementById('uploader').style.display = "none";
			document.getElementById('preview_v').style.display = "block";
			video.play();
		},
		function(err) {
			console.log("Erreur lors du chargement du flux vidéo : " + err);
		}
	);

	video.addEventListener('canplay', function(ev){
		if (!streaming) {
			height = video.videoHeight / (video.videoWidth/width);
			video.setAttribute('width', width);
			video.setAttribute('height', height);
			streaming = true;
		}
	}, false);

	video.addEventListener('click', function(ev){
		takepicture();
		ev.preventDefault();
	}, false);

	function takepicture() {
		if (document.querySelector('input[name="effect"]:checked').value != -1) {
			var shot = document.createElement('canvas');
			shot.width = width;
			shot.height = height;
			shot.getContext('2d').drawImage(video, 0, 0, width, height);
			shot.toBlob(function(blob){
				var form = new FormData(document.getElementById('upform'));
				form.set('action', '⬆️');
				form.set('data', blob);
				form.set('effect', document.querySelector('input[name="effect"]:checked').value);

				function reqListener () {
					console.log(this.responseText);
					window.location.href = "/";
				}
				var request = new XMLHttpRequest();
				request.addEventListener("load", reqListener);
				request.open("POST", "?pics");
				request.send(form);
			});
		}
		else {
			alert("Sélectionnez un effet avant de prendre une photo !")
		}
	}

})();
