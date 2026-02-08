```bash
# Set build-time argument
# This argument can be further refered as '${DEBIAN_VERSION}'
# This argument is only used by image built process, will not written into the image
ARG DEBIAN_VERSION=stable-20241016-slim

# Define environment variables
# This environment variable will be baked into the image and take effect when the container runs.
ENV NODE_ENV=production

# Choose a base image
FROM node:latest

# Set default shell during Docker image build
# It means all the RUN commands should be executed with bash
SHELL ["/bin/bash", "-c"]

# Execute shell command with setted shell
# Run commands are also be executed during image build process
# Here e.g. create and set the working directory
RUN mkdir -p /home/app
WORKDIR /home/app

# Copy from host to image
# src: relative path with Dockerfile
# dest: path inside image
COPY ./scripts/entrypoint.sh /entrypoint.sh

# Specify the default command to run when the container starts
# note: only the last command will be executed
# more commands can be executed with shell script, e.g. ENTRYPOINT ["/entrypoint.sh"]
CMD ["node", "server.js"]
```