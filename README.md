# TCP Network

**Chat TCP in development**
____
## О проекте:
чат сервер основа на tcp соединении , поддерживает отправку различных пакетов, на данном этапе разработки есть тестовый пакет и пакет с сообщениями. Сервер поддерживает может поддерживать до 100 человек одновременно , благодаря реализации много поточности внутри клиента и сервера.

Для более разборчивого понимания пользователи могут отличить себя от остальных , благодаря ключевой фразе another user

```mermaid
graph LR
A((Клиент)) -- Запрос --> B{Сервер}
A1((Клиент 2)) -- Запрос 2 --> B
A2((Клиент N)) -- Запрос N --> B
B --> D(Обработка)
D --> C[Определитель клиента]
C -- Ответ 1 --> A
C -- Ответ 2 --> A1
C -- Ответ N --> A2
```

```mermaid
gantt 
	dateFormat YYYY-MM-DD 
	title Процесс разработки
	section A section 
	Сервер 	:done, 	des1, 2020-09-15, 2d 
	Клиент 	:done, 	des2, 2020-09-15, 2d 
	Объединить 	:done, 	des3, 2020-09-16, 2d 
	Сдать практику 	:done, 		des4, 2020-09-20, 1d
	Сдать лектору 	:active, 	des5, after des4, 2020-12-01
```

```mermaid
journey 
	title My working day 
	section Go to work 
		Make server: 5: Anton 
		Make client: 5: Maxim
		Make style: 5: Gleb
		Merge: 4: Anton, Maxim, Gleb 
	section Push 
		Push on git: 5: Anton, Maxim 
		Create README: 5: Anton
```

### Технологии:

TCP.

### Created by:

- **Anton Biluta [(antonbiluta)](https://github.com/antonbiluta)**

- **Maksim Bobrovskii [(Slimenion)](https://github.com/Slimenion)**

- **Gleb Bushelenkov**
##### Таблица работы:
|                |Обязанности               |Выполнено                         |
|----------------|--------------------------|-----------------------------|
|Anton			|`Сервер`        |'Готово'            |
|Maxim          |`Клиент`        |"Готово"            |
|Gleb          |`-- Страдать --- херней`|-- как всегда, --- безупречно|

```mermaid
sequenceDiagram
Anton ->> Maxim: Давай разделим задачи?
Maxim -->> Anton: Думаю да, это хорошая идея.
Maxim ->> Gleb: Как ты на это смотришь?
Gleb->> Maxim: Согласен!
Maxim->> Anton: Мы согласны!
Note right of Anton: Так мы и поделили<br/>проект<br/>На сервер<br/>и клиент.
```
____
> **Заметка:** Здесь **большинство** информации создано для эксперимента.
