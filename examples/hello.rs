use glfw::WindowMode;
use sask::glfw::{Action, Key, WindowEvent};
use sask::{App, Event, Window};

fn main() -> Result<(), sask::Error> {
    let mut app = App::new()?;
    let mut window = Window::new(&mut app, 800, 600, "Example game", WindowMode::Windowed)?;
    let mut ticks = 0;

    while let Some(event) = window.next() {
        match event {
            Event::Tick => ticks += 1,
            Event::WindowEvent(e) => match e {
                WindowEvent::Key(Key::Escape, _, Action::Press, _) => {
                    window.close();
                }
                _ => {}
            },
        }
    }

    println!("Total ticks: {ticks}");

    Ok(())
}
