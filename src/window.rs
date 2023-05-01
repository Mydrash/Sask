use std::sync::mpsc::Receiver;

use crate::{App, Event};

use crate::error::UnableToCreateWindowSnafu;
use crate::Result;
use glfw::{Context, WindowMode};
use snafu::OptionExt;

pub struct Window<'a> {
    pub handle: glfw::Window,
    pub app: &'a mut App,
    events: Receiver<(f64, glfw::WindowEvent)>,
}

impl<'a> Window<'a> {
    pub fn new(
        app: &'a mut App,
        width: u32,
        height: u32,
        title: &str,
        mode: WindowMode,
    ) -> Result<Self> {
        let (mut handle, events) = app
            .glfw
            .create_window(width, height, title, mode)
            .context(UnableToCreateWindowSnafu)?;

        handle.make_current();
        handle.set_key_polling(true);

        Ok(Self {
            handle,
            events,
            app,
        })
    }

    #[inline]
    pub fn close(&mut self) {
        self.handle.set_should_close(true);
    }
}

impl<'a> Iterator for Window<'a> {
    fn next(&mut self) -> Option<Self::Item> {
        self.app.glfw.poll_events();

        if let Some((_, event)) = glfw::flush_messages(&self.events).next() {
            return Some(Event::WindowEvent(event));
        }

        if self.handle.should_close() {
            return None;
        }

        Some(Event::Tick)
    }

    type Item = Event;
}
