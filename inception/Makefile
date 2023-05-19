all : up

up:
	mkdir -p /home/youhan/data/wordpress /home/youhan/data/mariadb
	docker compose -f ./srcs/docker-compose.yml up --build

down:
	docker compose -f ./srcs/docker-compose.yml down -v

fclean:
	@make down
	rm -rf /home/youhan/data
	docker system prune --volumes --all --force
	docker network prune --force
	docker volume prune --force

re:
	@make down
	@make all

.PHONY: all up down fclean re
