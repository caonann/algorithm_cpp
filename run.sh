#!/bin/bash
set -x
name=alguint
containerid=`docker container ls -a -f "name=${name}" -q`
if [ -z ${containerid} ];then
    docker run -it --name ${name} --rm --mount type=bind,source=$(pwd),target=/app ${name}
else
    docker exec -it ${containerid} /bin/bash
fi
