```bash
docker pull [image_id]: # download the docker image
docker images: # show all existing docker images
docker rmi [image_id]: # delete docker image

# docker run == docker pull + docker start
docker run [image_name]: # run the image(start a container) with image name
-d  # run the image with detached mode
-p [host_port]:[container_port]: # binding host port to container port 
-e # environment variable 
--name [user_specified_name]: # create container with user defined name
--net [net_name]: # run container under certain docker net

docker network create [network_name]

docker ps: # process status, list all the running docker continers
docker ps -a: # list all the running and stopped containers

docker rm [container_id]: # delete container

docker stop [container_id]: # stop a container with the containr id (not the whole id string but only the id shown with 'docker ps' command)
docker start [container_id]: # start the container with the container id

docker logs [container_id]: # show logs inside the container (container name can be sued as well)

docker exec -it [container_id] /bin/bash: # use bash inside the container

docker-compose -f file.ymal up
docker-compose -f file.ymal down

docker build -t [image_name]:[tag] -f [Dockerfile] [saved_path]: # build docker image with Dockerfile

docker login # login to docker registory

docker volume --help # command relavnt with docker volume
```