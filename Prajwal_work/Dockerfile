From ubuntu:18.04
#EXPOSE 8081
COPY helloworld.txt .  
#CMD ["echo","Hello World.."]
CMD /bin/bash -c "trap : TERM INT; sleep infinity & wait"
