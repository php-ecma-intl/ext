FROM ubuntu:22.04

ARG icuVersion
ARG phpVersion

ENV DEBIAN_FRONTEND=noninteractive

SHELL ["/bin/bash", "-c"]

# Configure the system for building ICU and PHP.
RUN apt-get update \
    && ln -fs /usr/share/zoneinfo/Etc/UTC /etc/localtime \
    && apt-get install -y \
        autoconf \
        automake \
        bison \
        ca-certificates \
        clang \
        cmake \
        curl \
        g++ \
        gcc \
        gdb \
        libc6-dev \
        libcurl4-openssl-dev \
        libonig-dev \
        libpcre2-dev \
        libsqlite3-dev \
        libssl-dev \
        libtool \
        libzip-dev \
        locales \
        make \
        pkg-config \
        re2c \
        shtool \
        tzdata \
        zip \
        zlib1g-dev \
    && dpkg-reconfigure --frontend noninteractive tzdata \
    && locale-gen en_US.UTF-8

# Install ICU
RUN export icuDash="${icuVersion//./-}" \
    && export icuUnder="${icuVersion//./_}" \
    && cd /tmp \
    && curl -LOs "https://github.com/unicode-org/icu/releases/download/release-${icuDash}/icu4c-${icuUnder}-src.tgz" \
    && tar -zxf "icu4c-${icuUnder}-src.tgz" \
    && cd icu/source/ \
    && ./runConfigureICU Linux \
    && make -j$(nproc) \
    && make install \
    && ldconfig \
    && cd /tmp \
    && rm -rf /tmp/icu "/tmp/icu4c-${icuUnder}-src.tgz"

# Install PHP
RUN cd /tmp \
    && curl -LOs "https://www.php.net/distributions/php-${phpVersion}.tar.xz" \
    && tar -Jxf "php-${phpVersion}.tar.xz" \
    && cd "php-${phpVersion}/" \
    && ./configure \
        --enable-debug \
        --enable-intl \
        --enable-mbstring \
        --enable-opcache \
        --enable-opcache-jit \
        --enable-zts \
        --with-config-file-scan-dir=/usr/local/etc/php.conf.d \
        --with-curl \
        --with-layout=GNU \
        --with-openssl \
        --with-zip \
        --with-zlib \
    && make -j$(nproc) \
    && make install \
    && mkdir -p "$(php-config --extension-dir)" \
    && mkdir -p "$(php-config --ini-dir)" \
    && cp php.ini-development "$(php-config --ini-path)/php.ini" \
    && cd /tmp \
    && rm -rf "/tmp/php-${phpVersion}" "/tmp/php-${phpVersion}.tar.xz"

# Force creation of a symlink to ecma_intl.so in the PHP extension directory,
# even though it does not yet exist. We will build the extension in /ext/modules,
# and we want PHP to be able to find it when we run tests.
RUN mkdir /ext \
    && ln -fs /ext/modules/ecma_intl.so "$(php-config --extension-dir)/ecma_intl.so"

# Add additional tools
COPY composer-install.sh /usr/bin
RUN apt-get update \
    && apt-get install -y \
        git \
        libcriterion-dev \
        valgrind \
    && /usr/bin/composer-install.sh \
    && mv composer.phar /usr/bin/composer \
    && rm /usr/bin/composer-install.sh

WORKDIR /ext
