**BT2**: Music Player Using State Pattern

*Description*:
- You are required to design a simple music player software. This music player can be in various states such as: **Stopped, Playing, Paused**. The behavior of control buttons (e.g., Play, Pause, Stop) will change depending on the current state of the music player.

- Apply the State Pattern to manage the states and behavior of the music player. The goal is to make the **MusicPlayer (Context)** able to change its behavior when the **state (PlayerState)** changes. **Concrete states (ConcreteState)** will define behavior for each state and can transition the MusicPlayer's state themselves.

*Implementation details for components*:

1. **MusicPlayer (Context)**:
   1. The main class that manages the current state of the music player.
   2. Will delegate actions (e.g., pressing play, pause, stop buttons) to the current state object.
   3. Has the ability to change its own state.

2. **PlayerState (State Interface)**:
   1. An interface that defines actions that all concrete states must implement (e.g., pressPlay(), pressPause(), pressStop()).
   2. May include a method to set a back-reference to MusicPlayer (e.g., setContext(player: MusicPlayer)).

3. **StoppedState, PlayingState, PausedState (ConcreteStates)**:
   1. Concrete classes that implement the PlayerState interface.
   2. Each class will provide specific behavior for actions when the music player is in the corresponding state.
      1. Example: In StoppedState, pressPlay() will transition to PlayingState and start playing music. pressPause() does nothing.
      2. In PlayingState, pressPlay() may do nothing or restart the song. pressPause() will transition to PausedState. pressStop() will transition to StoppedState.
   3. These ConcreteStates can contain a reference to MusicPlayer (context) to be able to request MusicPlayer to change its state (e.g., player.changeState(new PlayingState(this.player))).

4. **Client (Initializer/User/main() function)**:
   1. Initialize a MusicPlayer object with an initial state (e.g., StoppedState).
   2. Simulate user interactions by calling methods on MusicPlayer (e.g., player.clickPlayButton(), player.clickPauseButton()).

*Sample workflow*:

1. The **main()/Client** function creates a MusicPlayer with initialState as new StoppedState().
2. MusicPlayer sets currentState to StoppedState and calls stoppedState.setContext(playerInstance).
3. Client calls player.clickPlayButton().
4. MusicPlayer delegates to currentState (which is StoppedState): stoppedState.pressPlay().
5. Inside StoppedState.pressPlay():
   1. Print "Starting to play music..."
   2. Call this.player.changeState(new PlayingState(this.player)) to transition MusicPlayer to PlayingState.
6. MusicPlayer now has currentState as PlayingState.
7. Client calls player.clickPauseButton().
8. MusicPlayer delegates to currentState (which is PlayingState): playingState.pressPause().
9. Inside PlayingState.pressPause():
   1. Print "Pausing music..."
   2. Call this.player.changeState(new PausedState(this.player)).
10. ... and so on.

*Goals to achieve*:

* MusicPlayer's behavior changes flexibly based on its current state.
* Easy to add new states (e.g., BufferingState, ErrorState) without needing to modify much of MusicPlayer's source code or existing states.
* Source code for each state is encapsulated separately, making management and maintenance easier.
* Both MusicPlayer (Context) and PlayerState (ConcreteState) can initiate state transitions, as described in the diagram.

---

*Answer*:

The State Pattern is used to manage the different states and behaviors of the music player. In this design, the `music_player_t` (Context) holds a reference to its current state, which implements the `player_state_t` interface. Each concrete state (`StoppedState`, `PlayingState`, `PausedState`) defines specific behaviors for the control buttons and can transition the player to other states as needed.

**Implementation highlights:**
- **music_player_t (Context):**
  - Maintains a pointer to the current state (`current_state`).
  - Provides methods for user actions: `click_play_button`, `click_pause_button`, and `click_stop_button`. Each method delegates the action to the current state's corresponding function.
  - Provides a `change_state` method to update the current state and set the context for the new state.
- **player_state_t (State Interface):**
  - Defines the interface for state-specific behaviors: `press_play`, `press_pause`, `press_stop`, and `set_context`.
  - Each concrete state implements these functions to define its own behavior and handle transitions.
- **Concrete States:**
  - `stopped_state_t`, `playing_state_t`, and `paused_state_t` each implement the `player_state_t` interface, encapsulating the logic for each state and managing transitions by calling `change_state` on the context.
  - Each state holds a reference to the context (`music_player_t* context`) and uses it to trigger state transitions.
  - For example:
    - In `StoppedState`, pressing Play prints "Starting to play music..." and transitions to `PlayingState`.
    - In `PlayingState`, pressing Pause prints "Pausing music..." and transitions to `PausedState`; pressing Stop prints "Stopping music..." and transitions to `StoppedState`.
    - In `PausedState`, pressing Play prints "Resuming music..." and transitions to `PlayingState`; pressing Stop prints "Stopping music from paused state..." and transitions to `StoppedState`.
- **Client (main.c):**
  - Initializes the music player in the stopped state and simulates user interactions by calling the button methods.

**How this solves the problems:**
- **Flexible behavior:** The music player's behavior changes automatically based on its current state, without complex conditional logic in the context.
- **Easy extensibility:** New states (e.g., BufferingState, ErrorState) can be added with minimal changes to existing code, simply by implementing the `player_state_t` interface and following the same pattern.
- **Encapsulation:** Each state's logic is encapsulated in its own module, improving maintainability and clarity. The context and states interact only through well-defined interfaces.
