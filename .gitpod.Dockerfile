FROM gitpod/workspace-full-vnc:latest

# install dependencies
RUN sudo apt-get update \
    && sudo apt-get install -y libgl1-mesa-dev libxkbcommon-x11-0 libx11-dev libxkbfile-dev libsecret-1-dev libgconf2-dev libnss3 libgtk-3-dev libasound2-dev twm \
    && sudo apt-get clean && sudo rm -r /var/cache/apt/* && sudo rm -r /var/lib/apt/lists/*
