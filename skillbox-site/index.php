<!DOCTYPE html>
<html lang="ru">
<head>
	<link rel="stylesheet" type="text/css" href="styles.css">
	<meta charset="utf-8">
	<title>Skillbox First Site</title>
	<script type="text/javascript" src="js/scripts.js"></script>
	<script type="text/javascript" src="js/jquery-3.3.1.js"></script>
	<script type="text/javascript">
		$(function(){
			$("#order-call").click(function(){
				$('#popup-container').css('display', 'flex')
			});
			$("#popup-container").click(function(e){
				if(this === e.target) {
					$("#popup-container").css('display', 'none');
				};
			});
		});
	</script>
</head>
<body>
<!--	<?
		$moneyAmount = 120;

		$cappucinoPrice = 200;
		$espressoPrice = 80;

		if ($moneyAmount >= $cappucinoPrice) {
			echo "You can buy Cappucino!";
		};
		if ($moneyAmount >= $espressoPrice) {
			echo "You can buy Espresso!";
		};
	?>; -->
	<div id="popup-container">
		<div id="popup">
			<div id="popup-text">
				Введите Ваш телефон в поле ниже и мы обязательно перезвоним Вам!
			</div>
			<div id="popup-form">
				<textarea></textarea>
			</div>
		</div>
	</div>
	<div id="container-1">
		<div id="block-1" class="mainblock">
			<div id="menu">
				<div class="left" id="menu-links">
					<a href="#">Услуги</a>
					<a href="#">Портфолио</a>
					<a href="#">Цена</a>
				</div>
					<div class="right" id="phone-block">
						<div id="phone">+7 919 919 99 11</div>
						<button id="order-call" class="btn">Заказать звонок</button>
					</div>
			</div>
		</div>
	</div>
	
	<div id="container-2">
		<div id="block-2" class="mainblock">
			<div id="left-block-2" class="left">
				<div id="text-1-block-2" class="left">
					Дмитрий Алексеев
				</div>
				<div id="text-2-block-2" class="left">
					Frontend-разработчик и веб-верстальщик
				</div>
				<button id="more-button" class="btn">
					Узнать больше
				</button>
			</div>
			<img src=" ./img/Dmitry Alekseev.png " 
			alt="Dmitry Alekseev" width="360px" height="384px" 
			style="position: static;
					display: flex;
					margin-right: 0;
					margin-left: auto;
					left: 53.1%;">
		</div>
	</div>

	<div id="container-3">
		<div id="block-3" class="mainblock">
			<div id="text-1-block-3">Что я делаю</div>
			<div id="img-text-block-3">
				<div id="img-block-3">
					<div><img src="./img/icons/1-verst.png"></div>
					<div><img src="./img/icons/2-adapt.png"></div>
					<div><img src="./img/icons/3-dev.png"></div>
					<div><img src="./img/icons/4-coding.png"></div>
				</div>
				<div id="text-2-block-3">
					<div>Вёрстка лендинг-страниц и сайтов любой сложности</div>
					<div>Адаптивная вёрстка под все браузеры и устройства</div>
					<div>Frontend-разработка и программирование</div>
					<div>Исправление и доработка существующей вёрстки</div>
				</div>
			</div>
			<div id="btn-div-block-3"><button id="btn-block-3">Узнать стоимость</button></div>
		</div>
	</div>

	<div id="container-4">
		<div id="block-4" class="mainblock">
			<div id="text-1-block-4">Примеры моих работ</div>
			<div id="img-text-block-4">
				<div id="img-block-4">
					<div>
						<img src="./img/1-port.png" alt="Сайт психолога Веры Антоновой" width="290px" height="227px">
					</div>
					<div>
						<img src="./img/2-port.png" alt="Сайт магазина детской одежды" width="290px" height="227px">
					</div>
					<div>
						<img src="./img/3-port.png" alt="Сайт магазина «Рыболов»" width="290px" height="227px">
					</div>
				</div>
				<div id="text-2-block-4">
					<div>Сайт психолога Веры Антоновой</div>
					<div>Сайт магазина детской одежды</div>
					<div>Сайт магазина «Рыболов»</div>
				</div>
			</div>
			<div id="btn-div-block-4"><button id="btn-block-4">Заказать проект</button></div>
		</div>
	</div>

	<div id="container-5">
		<div id="block-5" class="mainblock">
			<div id="text-block-5">
				<div id="maintext-block-5">
					<div id="text-1-block-5">Адаптивная вёрстка под все устройства</div>
					<div id="text-2-block-5">и браузеры от 1000 рублей всего за 4 часа.*</div>
				</div>
				<div id="startext-block-5">
					<div id="text-3-block-5">* Срок и стоимость могут отличаться от заявленных и рассчитываются индивидуально,</div>
					<div id="text-4-block-5">в зависимости от сложности задач.</div>
				</div>
			</div>
		</div>
	</div>
</body>
</html>