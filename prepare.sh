#!/usr/bin/env bash

apt upgrade
apt update
apt-get install -y openjdk-8-jdk
export JAVA_HOME=/usr/lib/jvm/java-8-openjdk-i386 #if yours is different, modify it here
export PATH=$PATH:$JAVA_HOME/bin
apt-get install -y build-essential cmake wget git
wget https://ftp.gnu.org/pub/gnu/libiconv/libiconv-1.15.tar.gz
tar zxf libiconv-1.15.tar.gz
cd libiconv-1.15
./configure --prefix=/usr/local
make
make installl
ldconfig
apt update