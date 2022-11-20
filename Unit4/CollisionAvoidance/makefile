CC=gcc
CFLAGS=-I.
DEPS = dc_motor.h us_sensor.h collision_avoidance.h state.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: main.o dc_motor.o us_sensor.o collision_avoidance.o 
	$(CC) -o hellomake main.o dc_motor.o us_sensor.o collision_avoidance.o 
clean:
	rm -f *.o *.exe