FROM gitpod/workspace-full-vnc:latest

# install dependencies
RUN sudo apt-get update \
    && sudo apt-get install -y xcb libgl1-mesa-dev libxcb-shape0 libxcb-image0 libxcb-icccm4 libxcb-randr0 libxcb-keysyms1 libxcb-render-util0 libxcb-xkb1 libxkbcommon-x11-0 libx11-dev libxkbfile-dev libsecret-1-dev libgconf2-dev libnss3 libgtk-3-dev libasound2-dev twm \
    && sudo apt-get clean
