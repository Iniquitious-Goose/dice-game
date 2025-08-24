import random

# These functions are used in multiple files, so they're here for ease of modification
def roll(min, max):
    return random.randint(min, max) # rolls the dice

def play_again(): # used at the end of every game. True repeats the game, false returns to main menu
    print("\nPlay again? yes/no")
    play = input().lower()
    if play == 'y' or play == 'yes':
        return True
    elif play =='honk' or play == "honk!": #Just an easter egg, doesn't really do anything notable
        honk_responses = [
            "Though Goose is impressed by your language skills, he still needs an answer.",
            "Goose tells you to watch your language, but repeats his question.",
            "Honk! (Very impressive! But I do need an answer.)",
            "Goose honks at your joke, but asks for an answer.",
            "Goose flaps his wings in response, but wants an answer.",
            "Honk! :) Wait... how did he make that sound out loud?",
            "Honk honk? (Would you like to play again?)",
            "I can actually speak, ya know. We don't *have* to honk.",
            "Quack-- honk! (Quack-- wait, geese don't quack!)",
            "Honk! (There are a few more easter eggs to find!)"
        ]
        print(honk_responses[roll(0, len(honk_responses ) -1)])
        return play_again()
    else:
        return False




def goose_boast():# another easter egg, with a random chance to be called on player loss
           goose_boasts =[
                "Honk! (Goose boasts at his victory.)",
                "Honk honk! ('Too easy'.)",
               "Honk! (Goose looks smug)",
               "Goose flaps his wings in triumph.",
                "Honk! ('Better luck next time!')"
           ]
           return goose_boasts[roll(0, len(goose_boasts) -1)]
            
def show_instructions():
    with open("instructions.txt") as file:
        print("\n" + file.read())


#deprecated due to removal of save system; kept for possible eventual update
# def show_high_score():