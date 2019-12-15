'''
Movie Reservation

# Sample code to perform I/O:

name = input()                  # Reading input from STDIN
print('Hi, %s.' % name)         # Writing output to STDOUT

# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''

# Write your code here

class Screen:
    
    def add_screen(self, ip):
        self.screen_name = ip[1]
        self.no_of_rows = int(ip[2])
        self.seats_per_row = int(ip[3])
        self.aisle_seats = []
        
        for x in ip[4:]:
            self.aisle_seats.append(int(x)-1)
        
        self.seat_map = [['E']*self.seats_per_row for _ in range(self.no_of_rows)]
        
        for i in range(self.no_of_rows):
            for x in self.aisle_seats:
                self.seat_map[i][x] = 'AE'
                


class Cinema:
    
    screens = {}
    
    def add_screen(self, ip):
        if ip[1] in self.screens:
            print("failure")
            return
        else:
            curr_screen = Screen()
            curr_screen.add_screen(ip)
            self.screens[ip[1]] = curr_screen
            print("success")
            return
        
    def reserve_seat(self, ip):
        screen_name = ip[1]
        row = int(ip[2])-1
        required_seats = []
        
        for x in ip[3:]:
            required_seats.append(int(x)-1)
            
        if screen_name in self.screens:
            
            # for x in self.screens[screen_name].seat_map:
            #     print(x)
            
            for x in required_seats:
                if row > self.screens[screen_name].no_of_rows-1  or x > self.screens[screen_name].seats_per_row-1 or  self.screens[screen_name].seat_map[row][x] == 'O' or self.screens[screen_name].seat_map[row][x] == 'AO':
                    print("failure")
                    return
                
            for x in required_seats:
                if self.screens[screen_name].seat_map[row][x] == 'E':
                    self.screens[screen_name].seat_map[row][x] = 'O'
                else:
                    self.screens[screen_name].seat_map[row][x] = 'AO'
            
            print("success")
            return
            
        else:
            print("failure")
            return
        
    
    def get_unreserved_seats(self, ip):
        screen_name = ip[1]
        row = int(ip[2])-1
        
        if screen_name in self.screens:
            for i in range(self.screens[screen_name].seats_per_row):
                if (self.screens[screen_name].seat_map[row][i] == 'E' or self.screens[screen_name].seat_map[row][i] == 'AE'):
                    print(i+1, end = ' ')
                
            print()
            
        # else:
        #     print("failure")
        #     return
        
    
    def suggest_contiguous_seats(self, ip):
        screen_name = ip[1]
        no_of_seats = int(ip[2])
        row = int(ip[3])-1
        choice = int(ip[4])-1
        
        interested_row = []
        for x in self.screens[screen_name].seat_map[row][:]:
            interested_row.append(x)
        
        # for x in interested_row:
        #     print(x)
        
        if screen_name in self.screens:
            
            if choice - no_of_seats + 1 >= 0:
                
                curr_seats = ['1']
                for j in range(choice - no_of_seats + 1, choice+1):
                    if interested_row[j] == 'O' or interested_row[j] == 'AO':
                        break
                    elif interested_row[j] == 'AE' and curr_seats[-1] == 'AE':
                        break
                    else:
                        curr_seats.append(interested_row[j])
                
                # for x in curr_seats:
                #     print(x)
                
                if len(curr_seats) == no_of_seats+1:
                    for j in range(choice - no_of_seats + 1, choice+1):
                        print(j+1, end = ' ')
                    print()
                    return
                
            if choice + no_of_seats < self.screens[screen_name].seats_per_row:
                curr_seats = ['1']
                for j in range(choice, choice + no_of_seats):
                    if interested_row[j] == 'O' or interested_row[j] == 'AO':
                        break
                    elif interested_row[j] == 'AE' and curr_seats[-1] == 'AE':
                        break
                    else:
                        curr_seats.append(interested_row[j])
                
                # for x in curr_seats:
                #     print(x)
                
                if len(curr_seats) == no_of_seats+1:
                    for j in range(choice, choice + no_of_seats):
                        print(j+1, end = ' ')
                    print()
                    return
            
                print("none")
                return
            
            
        # else:
        #     print("failure")
        #     return
        


# if __name__ == "main":
myCinema = Cinema()
n = int(input())
# print(n)
while(n):
    
    n = n-1
    
    ip = input().split()
    if(len(ip)==0):
        continue
    
    if ip[0] == "add-screen":
        myCinema.add_screen(ip)
    elif ip[0] == "reserve-seat":
        myCinema.reserve_seat(ip)
    elif ip[0] == "get-unreserved-seats":
        myCinema.get_unreserved_seats(ip)
    elif ip[0] == "suggest-contiguous-seats":
        myCinema.suggest_contiguous_seats(ip)
