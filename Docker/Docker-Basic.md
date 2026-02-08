### Host Port and Container Port

To interact with services running inside a container, you must publish a port on the host and map it to a port in the container. This is done with the `-p` (or `--publish`) flag of `docker run`, for example:

```bash
docker run -d -p <host_port>:<container_port> <image>
```

Key Points:

1. `<host_port>` is the port on your machine that you’ll connect to.
2. `<container_port>` is the port inside the container where the application is listening.
3. A single host port can only be bound to one container; attempting to reuse the same host port for multiple containers will produce a “port is already allocated” error.
4. If you omit the host port (e.g. `-p :80`), Docker will randomly assign an available high-numbered port on the host.

### Docker Network

On a single host machine, all containers run within the same Docker network. You can create this network yourself using the `docker network create` command, or let Docker provision a default network automatically. When containers share a network, applications in different containers can communicate with one another seamlessly.

### Docker Compose

Docker Compose streamlines Docker workflows by letting you define multi-container applications in a single YAML file. In that Compose file, you specify all services, networks, volumes, and configurations in a clear, human-readable format—and then bring up the entire stack with one command, for example:

```bash
docker compose up
```

### Dockerfile

A Dockerfile is the blueprint for building Docker images. It consists of a series of instructions that tell Docker how to assemble your image. More information can be refered from Docker-File.md.


Instruction breakdown:

1. `FROM node:latest`
    Selects the official Node.js image (latest tag) as your base.
2. `ENV NODE_ENV=production`
    Defines an environment variable inside the image, which your application can reference at runtime.
3. `RUN mkdir -p /home/app`
    Executes a shell command in a new image layer—here, creating the /home/app directory.
4. `WORKDIR /home/app`
    Sets the working directory for all subsequent instructions (RUN, COPY, CMD, etc.).
5. `COPY . .`
    Copies all files from your local project directory into /home/app inside the image.
6. `CMD ["node", "server.js"]`
Declares the default command to run when the container starts. You can override this at runtime with docker `run <image> <new command>`.

You can include as many RUN instructions as needed—each creates its own layer. Only the last CMD in the Dockerfile takes effect (if you have multiple, earlier ones are ignored).

### Docker Volumes

A Docker volume lets you persist and share data between your host and containers (or among containers) by mounting a directory into the container’s filesystem. Docker supports three primary volume types:

1. **Host volumes**
    Mounts an existing host directory into the container.
    ```bash
    docker run -v /path/on/host:/path/in/container <image>
    ```
2. **Anonymous volumes**
    Creates and mounts a new, ephemeral volume managed by Docker. The actual data lives under Docker’s internal storage (e.g. /var/lib/docker/volumes/…).
    ```bash
    docker run -v /path/in/container <image>
    ```
3. **Named volumes** (recommended)
    Creates (or reuses) a volume with a given name that you can reference across multiple containers. Docker stores named volumes in its internal directory, but you interact with them via their name.
    ```bash
    docker run -v my-data-volume:/path/in/container <image>
    ```

Why use named volumes?

- Reusability: Easily share data between containers by referring to the same volume name.
- Manageability: Inspect, back up, or clean up volumes with simple Docker commands (docker volume ls, docker volume rm).
- Decoupling: Keeps container configuration clean and avoids hard-coding host paths.